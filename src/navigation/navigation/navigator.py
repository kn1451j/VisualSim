"""
Naive navigator class simulating the state of a "robot" spinning in a circle
TODO -> connect this to the navigator node for it to make post requests
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
                 num_steps = 10.0, 
                 radius = 3.0):
        self.super.__init__(position, orientation)

        # we "parametrize" our navigation around this circle as a function of t
        self.steps = num_steps
        self.radius = radius

        # Distance to travel each timestep
        self.dr = self.radius/self.steps
        self.dt = 2*np.pi/self.steps
        self.theta = 0

        self.position = position
        self.orientation = orientation

        # Step
        self.trans = np.array([])

    # simulates a timestep
    def timestep(self):
        self.theta += self.dt
        self.position = np.array[self.radius * np.cos(self.theta), 0, self.radius*np.sin(self.theta)]
        self.orientation = np.array([[np.cos(self.theta), 0, np.sin(self.theta)], [0, 1, 0], [-np.sin(self.theta), 0, np.cos(self.theta)]])
                                 
