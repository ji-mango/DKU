def handle_collisions(self):
     for brick in self.bricks:
          if self.ball.colliderect(brick):
               self.snd.play()
               self.score+=3
               self.ball_vel[1]=-self.ball_vel[1]
               self.bricks.remove(brick)
               break
          if len(self.bricks)==0:
               self.state=STATE_WON
               pygame.mixer.music.stop()
          if self.ball.colliderect(self.paddle):
               self.ball.top=PADDLE_Y-BALL_DIAMETER
               self.ball_vel[1]=-self.ball_vel[1]
          elif self.ball.top>self.paddle.top:
               self.lives-=1
               if self.lives>0:
                    self.state=STATE_IN_PADDLE
               else:
                    self.state=STATE_GAME_OVER
                    pygame.mixer.music.stop()
                    
               
