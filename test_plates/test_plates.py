from plates import is_valid

def test_alphabetical():
    assert is_valid("ACBD") == True
    assert is_valid("AAAAAA") == True
    assert is_valid("PP") == True

def test_middle_numbers():
    assert is_valid("AB21CD") == False
    assert is_valid("PP2C") == False

def test_length():
    assert is_valid("LAHDEEDAH") == False
    assert is_valid("LAHDEE") == True
    assert is_valid("Q") == False

def test_end_numbers():
    assert is_valid("RU2112") == True
    assert is_valid("RUSH2112") == False
    assert is_valid("BOOB1") == True
    assert is_valid("BO0BS1") == False
    assert is_valid("BB01") == False