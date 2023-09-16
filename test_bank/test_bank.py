from bank import value

def test_value():
    assert value("Hello! You are stupid.") == "$0"
    assert value("Heyy! wassup!") == "$20"
    assert value("Eyy! wassup!") == "$100"
    assert value("1001001") == "$100"
