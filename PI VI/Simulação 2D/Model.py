from numpy import *

class Ground:
    '''
    type_terrain-> Type of Ground(Forest, low vegetation, agriculture, pasture or null area) -- STRING
    hi -> relative humidity(%) -- FLOAT
    n -> number of days without rainfall greater than or equal to 13 -- INT
    '''
    def __init__(self,type_terrain,hi,n):
        self.type = type_terrain
        self.hi = hi
        self.n = n
        print("-> Model Generated")
        
class Matrix_Map:
    '''
    This class is responsible for generating and using the ground matrix
    '''
    def __init__(self,dimention):
        self.dimention = dimention
        self.matrix = []

    def Input_Element(self, groundElement):
        self.matrix.append(groundElement)
        print("-> Element inputed")