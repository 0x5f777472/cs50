from fuel import convert, gauge
from pytest import raises

def test_convert():
    assert convert("1/2") == 50
    assert convert("99/100") == 99
    with pytest.raises(ZeroDivisionError, match='must be 0 or None'):
        raise ZeroDivisionError('value must be 0 or None')

def test_gauge():
    ...