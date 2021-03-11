from numpy import *

class Ground:
    '''
    type_terrain-> Type of Ground(Forest(0), low vegetation(1), agriculture(2), pasture(3) or null area(4)) -- INT
    hi -> relative humidity(%) -- FLOAT
    n -> number of days without rainfall greater than or equal to 13 -- INT
    '''
    def __init__(self,type_terrain,hi,n):
        self.type_terrain = int(type_terrain)
        self.hi = float(hi)
        self.n = int(n)
        print("-> Model Generated")
