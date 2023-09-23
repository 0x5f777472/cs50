from jar import Jar
from pytest import raises

def test_init():
    jar1 = Jar()
    assert jar1.capacity == 12
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
    jar = Jar()
    with raises(ValueError):
        jar.deposit(13)
    assert jar.size == 0 # whoa there
    jar.deposit(10)
    assert jar.size == 10


def test_withdraw():
    big_jar = Jar(100)
    big_jar.deposit(100)
    with raises(ValueError):
        big_jar.withdraw(101) # don't be greedy
    big_jar.withdraw(99) # nom nom nom
    assert big_jar.size == 1
