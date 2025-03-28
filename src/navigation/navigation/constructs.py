"""
Used by the navigator class to track position and orientation
TODO -> integrate this
"""

import numpy as np
import math

class Position:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0

    def to_array(self):
        return np.array([self.x, self.y, self.z])

class Orientation:
    def __init__(self):
        self.yaw = 0
        self.pitch = 0
        self.roll = 0

    def to_mat(self):
        yaw = self.yaw
        pitch = self.pitch
        roll = self.roll

        # Rotation matrices around individual axes
        R_z = np.array([[math.cos(yaw), -math.sin(yaw), 0],
                        [math.sin(yaw), math.cos(yaw), 0],
                        [0, 0, 1]])

        R_y = np.array([[math.cos(pitch), 0, math.sin(pitch)],
                        [0, 1, 0],
                        [-math.sin(pitch), 0, math.cos(pitch)]])

        R_x = np.array([[1, 0, 0],
                        [0, math.cos(roll), -math.sin(roll)],
                        [0, math.sin(roll), math.cos(roll)]])

        # Combined rotation matrix
        R = np.dot(R_z, np.dot(R_y, R_x))

        return R