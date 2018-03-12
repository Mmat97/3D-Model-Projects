import pygame


pygame.init()







gameDisplay=pygame.display.set_mode((800,600), 0, 32)
pygame.display.set_caption('Rice');


riceimg=pygame.image.load("/Users/michaelmathew/Desktop/rice.jpg");



def rice(x,y):
    gameDisplay.blit(riceimg,(x,y))


x=(800*.05)
y=(600*.5)



destroyed=False

while not destroyed:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            destroyed=True

    rice(x,y)
    pygame.display.update()

pygame.quit()
quit()
