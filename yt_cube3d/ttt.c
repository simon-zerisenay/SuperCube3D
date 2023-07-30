// import math

// # Define the size of the grid and the player's position and direction
// GRID_SIZE = 10
// player_x = 3.0
// player_y = 3.0
// player_angle = 0.0  # Angle in radians (0 = facing right, pi/2 = facing up, pi = facing left, 3*pi/2 = facing down)

// # Define walls or obstacles in the scene (represented by their endpoints)
// walls = [((1, 1), (1, 6)),
//          ((1, 1), (6, 1)),
//          ((6, 1), (6, 6)),
//          ((1, 6), (6, 6))]

// # Define the screen size (number of columns and rows)
// screen_width = 80
// screen_height = 40

// # Define the field of view (FOV) angle
// fov = math.pi / 3.0

// # Ray casting algorithm
// for screen_column in range(screen_width):
//     # Calculate the angle of the current ray based on the player's angle and FOV
//     ray_angle = player_angle - fov / 2.0 + (fov * screen_column) / screen_width
    
//     # Initialize the ray's position and direction
//     ray_x = player_x
//     ray_y = player_y
//     ray_dx = math.cos(ray_angle)
//     ray_dy = math.sin(ray_angle)
    
//     # Cast the ray until it hits a wall or reaches the grid boundary
//     while 0 <= ray_x < GRID_SIZE and 0 <= ray_y < GRID_SIZE:
//         # Check for intersections with walls
//         for wall_start, wall_end in walls:
//             x1, y1 = wall_start
//             x2, y2 = wall_end
            
//             # Use line-segment intersection test to check if the ray intersects the wall
//             if x1 <= ray_x <= x2 and y1 <= ray_y <= y2:
//                 # Wall hit, calculate the distance to the intersection point
//                 distance_to_wall = math.sqrt((ray_x - player_x) ** 2 + (ray_y - player_y) ** 2)
                
//                 # Perform rendering based on distance (for simplicity, we just print 'X' for walls)
//                 if distance_to_wall <= GRID_SIZE:
//                     screen_row = int(screen_height / 2.0 - screen_height / (distance_to_wall + 1))
//                     print('X', end='')
//                 else:
//                     print(' ', end='')
                
//                 # Break the loop to stop the ray from traveling further
//                 break
//         else:
//             # No wall hit, continue casting the ray to the next grid cell
//             ray_x += ray_dx
//             ray_y += ray_dy
//     else:
//         # If the ray reaches the grid boundary without hitting a wall, render an empty space
//         print(' ', end='')
        
//     # Move to the next screen column
//     print()


#include <stdio.h>
#include <math.h>

// Define the size of the grid and the player's position and direction
#define GRID_SIZE 10
float player_x = 3.0;
float player_y = 3.0;
float player_angle = 0.0;  // Angle in radians (0 = facing right, M_PI/2 = facing up, M_PI = facing left, 3*M_PI/2 = facing down)

// Define walls or obstacles in the scene (represented by their endpoints)
typedef struct {
    float x1, y1;
    float x2, y2;
} Wall;

Wall walls[] = {{1, 1, 1, 6},
                {1, 1, 6, 1},
                {6, 1, 6, 6},
                {1, 6, 6, 6}};

// Define the screen size (number of columns and rows)
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40

// Define the field of view (FOV) angle
#define FOV (M_PI / 3.0)

// Ray casting algorithm
int main() {
    for (int screen_column = 0; screen_column < SCREEN_WIDTH; screen_column++) {
        // Calculate the angle of the current ray based on the player's angle and FOV
        float ray_angle = player_angle - FOV / 2.0 + (FOV * screen_column) / SCREEN_WIDTH;

        // Initialize the ray's position and direction
        float ray_x = player_x;
        float ray_y = player_y;
        float ray_dx = cos(ray_angle);
        float ray_dy = sin(ray_angle);

        // Cast the ray until it hits a wall or reaches the grid boundary
        while (ray_x >= 0 && ray_x < GRID_SIZE && ray_y >= 0 && ray_y < GRID_SIZE) {
            // Check for intersections with walls
            for (int i = 0; i < sizeof(walls) / sizeof(walls[0]); i++) {
                float x1 = walls[i].x1;
                float y1 = walls[i].y1;
                float x2 = walls[i].x2;
                float y2 = walls[i].y2;

                // Use line-segment intersection test to check if the ray intersects the wall
                if (x1 <= ray_x && ray_x <= x2 && y1 <= ray_y && ray_y <= y2) {
                    // Wall hit, calculate the distance to the intersection point
                    float distance_to_wall = sqrtf((ray_x - player_x) * (ray_x - player_x) +
                                                  (ray_y - player_y) * (ray_y - player_y));

                    // Perform rendering based on distance (for simplicity, we just print 'X' for walls)
                    if (distance_to_wall <= GRID_SIZE) {
                        int screen_row = SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / (distance_to_wall + 1);
                        printf("X");
                    } else {
                        printf(" ");
                    }

                    // Break the loop to stop the ray from traveling further
                    break;
                }
            }
            // No wall hit, continue casting the ray to the next grid cell
            ray_x += ray_dx;
            ray_y += ray_dy;
        }
        // If the ray reaches the grid boundary without hitting a wall, render an empty space
        printf("\n");
    }

    return 0;
}
