from bank import value

def test_value():
    assert value("Hello there ") == "$0"
    assert value("Heyyyyllo there ") == "$20"
    assert value("eyyyyllo there ") == "$100"
