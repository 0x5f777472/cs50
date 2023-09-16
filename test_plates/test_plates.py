from plates import is_valid

def test_alphabetical():
    assert is_valid("ACBD") == True
    assert is_valid("AAAAAA") == True
    assert is_valid("pp") == True

def test_middle_numbers():
    assert is_valid("AB21CD") == False
    assert is_valid("PP2C") == False

def test_length():
    assert is_valid("LahDeeDah") == False
    assert is_valid("LahDee") == True
    assert is_valid("Q") == False

def test_end_numbers():
    assert is_valid("RU2112") == True
    assert is_valid("RUSH2112") == False
    assert is_valid("boobs1") == True