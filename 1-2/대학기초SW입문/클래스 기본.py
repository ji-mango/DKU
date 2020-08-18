class Counter:
    def __init__(self, init_v):  #생성자
        self.count=init_v 

    def reset(self):
        self.count=0
        
    def increment(self):
        self.count+=1
        
    def get(self):
        return self.count
        

x=Counter()

#x=Counter(100)-->매개변수값을 줘야함
#def __init__(self, init_v=100): 으로 하면 안줘도됨

