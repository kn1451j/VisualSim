"""
Naive navigator class simulating the state of a "robot" spinning in a circle
"""
import numpy as np

class Navigator:
    def __init__(self, position, orientation):
        self.position = position # x y z array
        self.orientation = orientation # SO3 matrix (TODO -> quaternion)

    def rotate(self, rot):
        self.orientation = np.matmul(rot, self.orientation)

    def move(self, trans):
        self.position = self.position + trans

    def set(self, pos, rot):
        self.position = pos
        self.orientation = rot

    def timestep(self):
        pass

class CircleNavigator(Navigator):
    def __init__(self, position = np.array[0,0,0], 
                 orientation = np.diag(3), 
                 dt = 0.01, 
                 radius = 3):
        self.super.__init__(position, orientation)

        # we "parametrize" our navigation around this circle as a function of t
        self.dt = dt
        self.radius = 3
        self.t = 0

        self.full_rot = 2*np.pi*
    
    # simulates a timestep
    def timestep(self):
        