from numb3rs import validate

def test_validate():
    assert validate("255.255.255.255") == True
    assert validate("125.500.0.1") == False
    assert validate("512.512.512.512") == False
    assert validate("1.2.3.1000") == False
def test_cat():
    assert validate("cat") == False