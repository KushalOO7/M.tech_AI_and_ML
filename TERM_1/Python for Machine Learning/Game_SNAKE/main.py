# Build a screen and a moving block

import pygame
from pygame.locals import *
import time
import random

SIZE = 40
class Food:
    def __init__(self,screen):
        self.food = pygame.image.load("resources/apple.jpg").convert()
        self.screen = screen
        self.x = SIZE*3
        self.y = SIZE*3

    def show(self):
        self.screen.blit(self.food, (self.x, self.y))
        pygame.display.flip()

    def move(self):
        self.x = random.randint(0,17) * SIZE
        self.y = random.randint(0, 17) * SIZE

class Snake:
    def __init__(self, screen, length):
        self.length = length
        self.screen = screen
        self.block = pygame.image.load("resources/block.jpg").convert()
        self.x = [SIZE] * length
        self.y = [SIZE] * length
        self.direction = 'down'

    def increase_length(self):
        self.length+=1
        self.x.append(-1)
        self.y.append(-1)

    def show(self):
        for i in range(self.length):
            self.screen.blit(self.block, (self.x[i], self.y[i]))
        pygame.display.flip()

    def move_Up(self):
        self.direction = 'up'
        self.show()
    def move_Down(self):
        self.direction = 'down'
        self.show()
    def move_Right(self):
        self.direction = 'right'
        self.show()
    def move_Left(self):
        self.direction = 'left'
        self.show()

    def auto_move(self):

        for i in range(self.length-1,0,-1):
            self.x[i] = self.x[i - 1]
            self.y[i] = self.y[i - 1]


        if self.direction == 'up':
            self.y[0] -= SIZE
        if self.direction == 'down':
            self.y[0] += SIZE
        if self.direction == 'right':
            self.x[0] += SIZE
        if self.direction == 'left':
            self.x[0] -= SIZE

        self.show()

class Game:
    def __init__(self):
        pygame.init()
        pygame.mixer.init()
        self.play_background_music()
        self.tab = pygame.display.set_mode((720, 720))
        self.tab.fill((102, 0, 51))
        self.snake = Snake(self.tab, 1)
        self.snake.show()
        self.food = Food(self.tab)
        self.food.show()

    def is_Collision(self, x1, y1, x2 , y2):
        if x1 >= x2 and x1 < x2 + SIZE:
            if y1 >= y2 and y1 < y2 + SIZE:
                return True
        return False

    def play_sound(self, sound):
        snd = pygame.mixer.Sound(f"resources/{sound}.mp3")
        pygame.mixer.Sound.play(snd)

    def play_background_music(self):
        pygame.mixer.music.load("resources/bg_music_1.mp3")
        pygame.mixer.music.play()

    def background(self):
        bg = pygame.image.load("resources/background.jpg")
        self.tab.blit(bg , (0,0))

    def display_score(self):
        font = pygame.font.SysFont('arial',20)
        score = font.render(f"Score: {self.snake.length-1}", True, (0,255,0))
        self.tab.blit(score ,(630,10))

    def play(self):
        self.background()
        self.snake.auto_move()
        self.food.show()
        self.display_score()
        pygame.display.flip()

        # Collision between Snake and Food
        if self.is_Collision(self.snake.x[0], self.snake.y[0], self.food.x, self.food.y):
            self.play_sound("ding")
            self.snake.increase_length()
            self.food.move()

        # Collision between Snake itself
        for i in range(1,self.snake.length):
            if self.is_Collision(self.snake.x[0], self.snake.y[0], self.snake.x[i], self.snake.y[i]):
                self.play_sound("crash")
                raise "Game over"

    def show_game_over(self):
        self.background()
        font = pygame.font.SysFont('arial', 20)
        end_comment1 = font.render(f"Game is Over !!! Your Score is : {self.snake.length-1}", True, (255, 0, 0))
        self.tab.blit(end_comment1, (150, 300))
        end_comment2 = font.render("Press Enter to Retry Again. Press Backspace to Exit Game.", True, (255, 0, 0))
        self.tab.blit(end_comment2, (150, 350))
        pygame.display.flip()
        pygame.mixer.music.pause()

    def reset(self):
        self.snake = Snake(self.tab, 1)
        self.food = Food(self.tab)

    def run(self):
        running = True
        pause = False
        while running:

            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_BACKSPACE:
                        running = False

                    if event.key == K_RETURN:
                        pygame.mixer.music.unpause()
                        pause = False

                    if not pause:
                        if event.key == K_UP:
                            self.snake.move_Up()
                        if event.key == K_DOWN:
                            self.snake.move_Down()
                        if event.key == K_RIGHT:
                            self.snake.move_Right()
                        if event.key == K_LEFT:
                            self.snake.move_Left()

                elif event.type == QUIT:
                    running = False

            try:
                if not pause:
                    self.play()
            except Exception as e:
                self.show_game_over()
                pause = True
                self.reset()

            time.sleep(0.2)


if __name__=="__main__":
    game = Game()
    game.run()

    pygame.display.flip()
