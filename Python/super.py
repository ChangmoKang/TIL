"""
1. Class 상속에 대해 알아보고
2. super()의 사용법을 알아본다.
"""

class Hyundai(object):
    
    def __init__(self):
        print("I'm 현대")


class Car(object):
    
    def __init__(self):
        print("I'm a Car")


class SantaFe(Car, Hyundai):

    def __init__(self):
        # 방법 1
        Hyundai.__init__(self)
        Car.__init__(self)


        # 방법 2
        super().__init__()

        print("I'm SantaFe")


santa_fe = SantaFe()

"""
상속 받은 것을 호출 할 때 2가지 방법이 있는데

방법 1로 호출하면 지정해서 호출이 가능하여 만약 SantaFe가 2가지를 상속 받는 경우 둘 다 호출 할 수 있다.

방법 2로 호출하면 먼저 상속한 Car 밖에 호출이 불가하다.
"""
