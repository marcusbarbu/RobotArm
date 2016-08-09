import pygame
import time
import serial

ser = serial.Serial("COM5", 9600)
def categorize(value):
    value = "%.3f" % value
    value = (float(value)*-1)
    if (value<-.33):
        return 2
    if (value >= -.33 and value <.33):
        return 1
    if (value >= .33):
        return 0

pygame.init()        
pygame.joystick.init()
joylist = pygame.joystick.get_count()
gamepad = pygame.joystick.Joystick(0)
gamepad.init()

base_list = ["I","K","J"]
bottom_list = ["R","S","T"]
middle_list = ["O","P","Q"]
manipulator_list = ["A","B","C"]


while True:
    for event in pygame.event.get(): # User did something
        if event.type == pygame.QUIT: # If user clicked closeser
            done=True
        if event.type == pygame.JOYBUTTONDOWN:
            print("Joystick button pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("Joystick button released.")
            
    base_axis = gamepad.get_axis(2)
    bottom_axis = gamepad.get_axis(3)
    middle_axis = gamepad.get_axis(1)
    manip_axis = gamepad.get_axis(0)
    
    base_axis = categorize(base_axis)
    bottom_axis = categorize(bottom_axis)
    mid = categorize(middle_axis)
    manip = categorize(manip_axis)
    
    middle_val = middle_list[mid]
    bottom_val = bottom_list[bottom_axis]
    base_val = base_list[base_axis]
    manip_val = manipulator_list[manip]
    
    print middle_val, bottom_val, base_val, manip_val
    
    ser.write(middle_val)
    ser.write(bottom_val)    
    ser.write(base_val) 
    ser.write(manip_val)   

