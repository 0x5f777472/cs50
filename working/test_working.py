from working import convert
from pytest import raises

def test_not_times():
    with raises(ValueError):
        convert("cat")
    with raises(ValueError):
        convert("don't blink")
    with raises(ValueError):
        convert("12:60 AM to 13:12 PM")

def test_no_minutes():
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"

def test_yes_minutes():
    assert convert("9:00 AM to 5:00 AM") == "09:00 to 05:00"