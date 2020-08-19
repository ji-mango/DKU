class TV:
    serialNumber=0 #정적 변수(클래스 멤버),전체 객체를 통틀어 하나만 생성
    def __init__(self,channel=11,volume=9,onoff=True):
        TV.serialNumber+=1 #클래스명,정적변수/앞에 클래스명을 붙여 접근
        self.channel=channel
        self.volume=volume
        self.onoff=onoff

    def show(self):
        print("채널=",self.channel,"볼륨=",self.volume,"전원=",self.onoff)

    def setChannel(self,channel):
        self.channel=channel

    def setVolume(self,volume):
        self.volume=volume

#>>> a=TV()
#>>> a.serialNumber
#1
#>>> b=TV()
#>>> b.serialNumber
#2
#>>> a.serialNumber
#2
#>>> a.serialNumber=100
#>>> b.serialNumber
#2
#>>> TV.serialNumber=1000
#>>> b.serialNumber
#1000
#>>> a.serialNumber
#100
#>>> 
