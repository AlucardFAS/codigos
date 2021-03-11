import pygame
import sys

def init():
    try:
        screen = pygame.display.set_mode((720,480))
        clock = pygame.time.Clock()
        pygame.display.set_caption("Centro Universitário Senac - Projeto Integrador VI")
        pygame.display.flip()

        
        while True:
            event = pygame.event.wait()
            if event.type == pygame.QUIT:
                break
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    sys.exit()
    finally:
        pygame.quit()

def main():
    init()

if __name__ == "__main__":
    main()