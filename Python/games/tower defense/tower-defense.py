import pygame
import random

# Initialize pygame
pygame.init()

# Window dimensions
WIDTH = 800
HEIGHT = 600

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# Create the game window
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tower Defense")

# Game clock
clock = pygame.time.Clock()

# Define the tower class
class Tower(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((50, 50))
        self.image.fill(RED)
        self.rect = self.image.get_rect()
        self.rect.x = 0
        self.rect.y = 0

    def update(self):
        mouse_pos = pygame.mouse.get_pos()
        self.rect.x = mouse_pos[0] - self.rect.width // 2
        self.rect.y = mouse_pos[1] - self.rect.height // 2

# Define the enemy class
class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((30, 30))
        self.image.fill(BLACK)
        self.rect = self.image.get_rect()
        self.rect.x = random.randrange(WIDTH - self.rect.width)
        self.rect.y = random.randrange(-100, -40)
        self.speed = random.randrange(1, 4)

    def update(self):
        self.rect.y += self.speed
        if self.rect.top > HEIGHT:
            self.rect.x = random.randrange(WIDTH - self.rect.width)
            self.rect.y = random.randrange(-100, -40)
            self.speed = random.randrange(1, 4)

# Create groups for sprites
all_sprites = pygame.sprite.Group()
towers = pygame.sprite.Group()
enemies = pygame.sprite.Group()

# Create the player's tower
player_tower = Tower()
all_sprites.add(player_tower)
towers.add(player_tower)

# Main game loop
running = True
while running:
    # Process events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:  # Left mouse button
                new_tower = Tower()
                all_sprites.add(new_tower)
                towers.add(new_tower)

    # Update sprites
    all_sprites.update()

    # Check for collisions between towers and enemies
    hits = pygame.sprite.groupcollide(towers, enemies, False, False)
    for tower, enemy_group in hits.items():
        # Perform actions for each tower-enemy collision
        for enemy in enemy_group:
            enemy.kill()  # Remove the enemy

    # Draw the game
    window.fill(WHITE)
    all_sprites.draw(window)

    # Update the display
    pygame.display.flip()

    # Limit the frame rate
    clock.tick(60)

# Quit the game
pygame.quit()
