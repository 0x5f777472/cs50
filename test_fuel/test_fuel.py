from fuel import convert, gauge
from pytest import raises

def test_convert():
    assert convert("1/2") == 50
    assert convert("99/100") == 99
    with raises(ZeroDivisionError):
        convert("1/0")
    with raises(ValueError):
        convert("2/1")

def test_gauge():
    assert gauge()