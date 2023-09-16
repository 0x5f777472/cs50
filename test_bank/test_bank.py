from bank import value

def test_value():
    assert value("Hello! You are stupid.") == "$0"
    assert value("heyy! wassup!") == "$20"
    assert value("eyy! wassup!") == "$100"
