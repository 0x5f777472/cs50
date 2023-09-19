from working import convert
from pytest import raises

def test_not_times():
    with raises(ValueError):
        convert("cat")
    with raises(ValueError):
        convert("don't blink")

def no_minutes():
    assert convert("9 AM to 5 PM") == "9:00 to 17:00"

def yes_minutes():
    assert convert("9:00 AM to 5:00 AM") == "9:00 to 17:00"