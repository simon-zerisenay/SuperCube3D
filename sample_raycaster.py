# import pygame
# from pygame.locals import *
# from OpenGL.GL import *
# from OpenGL.GLU import *
# from math import cos, sin

# # Dimensions of the game window  
# WINDOW_WIDTH = 800
# WINDOW_HEIGHT = 600

# # Map representation (1 represents a wall, 0 represents empty space)
# MAP = [
# 	[1, 1, 1, 1, 1, 1, 1, 1],
# 	[1, 0, 0, 0, 0, 0, 0, 1],
# 	[1, 0, 0, 0, 0, 0, 0, 1], 
# 	[1, 0, 0, 0, 1, 0, 0, 1],
# 	[1, 0, 0, 0, 1, 0, 0, 1],
# 	[1, 0, 0, 0, 1, 1, 0, 1],
# 	[1, 0, 0, 0, 0, 0, 0, 1],
# 	[1, 1, 1, 1, 1, 1, 1, 1]
# ] 

# # Player position and viewing angle
# player_x = 3.5
# player_y = 3.5
# player_angle = 0.0

# def draw_map():
# 	for i in range(len(MAP)):
# 		for j in range(len(MAP[i])):
# 			if MAP[i][j] == 1:
# 				glColor3f(0.5, 0.5, 0.5)  # Wall color
# 			else:
# 				glColor3f(1.0, 1.0, 1.0)  # Empty space color

# 			glBegin(GL_QUADS)
# 			glVertex3f(j, i, 0.0)
# 			glVertex3f(j + 1, i, 0.0)
# 			glVertex3f(j + 1, i + 1, 0.0)
# 			glVertex3f(j, i + 1, 0.0)
# 			glEnd()

# def cast_ray():
# 	# Raycasting implementation goes here
# 	pass

# def render():
# 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
# 	glLoadIdentity()

# 	gluLookAt(player_x, player_y, 0.5,  # Eye position
# 			player_x + cos(player_angle), player_y + sin(player_angle), 0.5,  # Look at position
# 			0.0, 0.0, 1.0)  # Up direction

# 	draw_map()
# 	cast_ray()

# 	pygame.display.flip()

# def main():
# 	pygame.init()
# 	pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), DOUBLEBUF | OPENGL)
# 	gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0)

# 	while True:
# 		for event in pygame.event.get():
# 			if event.type == pygame.QUIT:
# 				pygame.quit()
# 				quit()

# 		# Update player position and angle based on input (not implemented in this example)
# 		# ...

# 		render()

# if __name__ == '__main__': 
# 	main()



import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
from math import cos, sin, radians

# Dimensions of the game window
WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600

# Map representation (1 represents a wall, 0 represents empty space)
MAP = [
	[1, 1, 1, 1, 1, 1, 1, 1],
	[1, 0, 0, 0, 0, 0, 0, 1],
	[1, 0, 0, 0, 0, 0, 0, 1],
	[1, 0, 0, 0, 1, 0, 0, 1],
	[1, 0, 0, 0, 1, 0, 0, 1],
	[1, 0, 0, 0, 1, 1, 0, 1],
	[1, 0, 0, 0, 0, 0, 0, 1],
	[1, 1, 1, 1, 1, 1, 1, 1]
]

# Player position and viewing angle
player_x = 3.5
player_y = 3.5
player_angle = 0.0

def draw_map():
	for i in range(len(MAP)):
		for j in range(len(MAP[i])):
			if MAP[i][j] == 1:
				glColor3f(0.5, 0.5, 0.5)  # Wall color
			else:
				glColor3f(1.0, 1.0, 1.0)  # Empty space color

			glBegin(GL_QUADS)
			glVertex3f(j, i, 0.0)
			glVertex3f(j + 1, i, 0.0)
			glVertex3f(j + 1, i + 1, 0.0)
			glVertex3f(j, i + 1, 0.0)
			glEnd()

def cast_ray(ray_angle):
	ray_x = player_x
	ray_y = player_y
	step_x = cos(ray_angle)
	step_y = sin(ray_angle)

	# Cast the ray until it hits a wall
	while MAP[int(ray_y)][int(ray_x)] == 0:
		ray_x += step_x
		ray_y += step_y

	# Draw the ray on the screen
	glBegin(GL_LINES)
	glColor3f(1.0, 0.0, 0.0)  # Ray color (red)
	glVertex3f(player_x, player_y, 0.0)  # Starting point of the ray
	glVertex3f(ray_x, ray_y, 0.0)  # Intersection point with the wall
	glEnd()

def render():
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glLoadIdentity()

	gluLookAt(player_x, player_y, 0.5,  # Eye position
			player_x + cos(radians(player_angle)), player_y + sin(radians(player_angle)), 0.5,  # Look at position
			0.0, 0.0, 1.0)  # Up direction

	draw_map()

	# Cast rays for each column of the screen
	for col in range(WINDOW_WIDTH):
		ray_angle = radians(player_angle - 30 + (col / WINDOW_WIDTH) * 60)  # Calculate the angle of the ray
		cast_ray(ray_angle)

	pygame.display.flip()

def main():
	pygame.init()
	pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), DOUBLEBUF | OPENGL)
	gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0)

	while True:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				quit()

		# Update player position and angle based on input (not implemented in this example)
		# ...

		render()

if __name__ == '__main__':
	main()
