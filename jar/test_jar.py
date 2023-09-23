from jar import Jar


def test_init():
    jar1 = Jar()
    assert jar.capacity == 12
    jar2 = Jar(1322980853407936018020929177243811840)
    assert jar2.capacity == 1322980853407936018020929177243811840 # what is the significance of this number?
    jar3 = Jar(0)
    assert jar3.capacity == 0


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    ...


def test_withdraw():
    ...
