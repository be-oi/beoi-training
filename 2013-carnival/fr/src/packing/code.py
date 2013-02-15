#!/usr/bin/env python
# -*- coding:utf-8 -*-
from sys import stdin

L, H, N = map(int,stdin.readline().split())

# --------------------------------------------------
# --------------------------------------------------
# Je mag de code hierboven niet aanpassen.    
# Vous n'etes pas cense modifier le code ci-dessus.        
# --------------------------------------------------
# --------------------------------------------------

data = []

def aaline(size,k=0):
   '''
       GÃ©nÃ©ration d'une ligne
   '''
   r = []
   for i in xrange(size):
       r.append(0)

   return r

def isFree(size,pos,show=False):
   global data
   ret = True
   arr = data[pos[1]:pos[1]+size[1]]
   r = []
   for line in arr:
       r.append(line[pos[0]:pos[0]+size[0]])

   if show == True:
       print r

   if pos[0]+size[0]-1 > L:
       return False
   if pos[1]+size[1]-1 > H:
       return False
   else:
       for line in r:
           if 1 in line:
               return False

       return ret

def showarr():
   '''
       Affiche bien le tableau
   '''
   global data
   for line in data:
       for elem in line:
           print elem,
       print ""

   print "\n\n"

def arrPlace(width,height):
   global data
   poss = []
   minFoundX = 1000000
   
   for y,line in enumerate(data):
       for x,val in enumerate(line):
           if x <= minFoundX:
               if isFree((width,height),(x,y)):
                   poss.append([x,H-y])
                   if x < minFoundX:
                       minFoundX = x

   minPoss = min(poss)
   minPoss[1] -= height-1
   if minPoss[1] != 0:
       minPoss[1] -= 1
   
   xMinPoss,yMinPoss = minPoss[0],minPoss[1]
   for a in xrange(width):
       for b in xrange(height):
           data[H-yMinPoss-b-1][xMinPoss+a] = 1

   print minPoss[0],minPoss[1]


pairs = 0
for i in xrange(H):
   data.append(aaline(L))

for i in xrange(N):
   LARG, HAUT = map(int,stdin.readline().split()) # input
   arrPlace(LARG,HAUT)

   
# --------------------------------------------------
# --------------------------------------------------
# Je mag de code hieronder niet aanpassen.
# Vous n'etes pas cense modifier le code ci-dessous        
# --------------------------------------------------
# --------------------------------------------------
