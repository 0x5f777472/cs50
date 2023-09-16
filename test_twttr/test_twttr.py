from twttr import shorten

def test_shorten():
    assert shorten("AEIOUaeiou - the ultimate test!1234567890") == " - th ltmt tst!1234567890"