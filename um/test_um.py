from um import count

def test_individual():
    assert count("blah um blah um blah") == 2
    assert count("blah um blah") == 1

def test_ends():
    assert count("Um blah Um") == 2
    assert count("Um blah") == 1

def test_punctuation():
    assert count("um, what? what, um, are, um, you, um, saying???? stop saying um") == 5
    assert count("um, do i have to swallow your cum?") == 1