#!/usr/bin/env python

# plot.py

# 2019.02.26 initial coding; greg.burgreen@msstate.edu

import sys
import string
import math

from pylab import *

#----------------------------------------------------------
def stats( data ):
#----------------------------------------------------------
  avg = 0.0
  for x in data: avg += x
  avg /= len(data)

  std = 0.0
  for x in data: std += (x-avg) * (x-avg)
  std = math.sqrt( std / ( len(data) - 1 ) )

  return (avg, std )

#----------------------------------------------------------
def s_read_data_csv( filename ):
#----------------------------------------------------------
  print('reading ', filename)
  fp = open( filename,'r' )

  line = 1
  line = fp.readline()
  data = {}
  tol = 1.e-05
  re = 0
  while line:
    line = fp.readline().rstrip('\r\n')
    s = str.split( line,',' )
    if not line: break
    if s[0] != re:
      re = s[0]
      data[re] = {}
      data[re]['dudy'] = []
      data[re]['tke'] = []
      data[re]['u'] = []
      data[re]['v'] = []
      data[re]['w'] = []
      data[re]['c'] = []

    data[re]['dudy'].append( float(s[2]) )
    data[re]['tke'].append( float(s[3]) )
    data[re]['u'].append( float(s[4]) )
    data[re]['v'].append( float(s[5]) )
    data[re]['w'].append( float(s[6]) )
    data[re]['c'].append( float(s[7]) )
    #print(data.keys())
    #print(data[re].keys())
    #print(data[re]['u'])
    #exit(1)

  return data

#-------------------------------------
def main( file, which_re, predicted ):
#-------------------------------------

  data = s_read_data_csv( file )
  keys = list(data.keys())
  k = keys[which_re]
  print( k )

  if predicted != 'undefined':
    pred = s_read_data_csv( predicted )
    keys = list(pred.keys())
    p = keys[which_re]
  
  d1 = loglog( data[k]['dudy'], data[k]['u'], '-', marker='None', markersize=1, lw=1, c='r' )
  d2 = loglog( data[k]['dudy'], data[k]['v'], '-', marker='None', markersize=1, lw=1, c='k' )
  d3 = loglog( data[k]['dudy'], data[k]['w'], '-', marker='None', markersize=1, lw=1, c='b' )
  d4 = loglog( data[k]['dudy'], data[k]['c'], '-', marker='None', markersize=1, lw=1, c='g' )
  if predicted != 'undefined':
    p1 = loglog( pred[p]['dudy'], pred[p]['u'], ':', marker='+', markersize=1, lw=1, c='r' )
    p2 = loglog( pred[p]['dudy'], pred[p]['v'], ':', marker='+', markersize=1, lw=1, c='k' )
    p3 = loglog( pred[p]['dudy'], pred[p]['w'], ':', marker='+', markersize=1, lw=1, c='b' )
    p4 = loglog( pred[p]['dudy'], pred[p]['c'], ':', marker='+', markersize=1, lw=1, c='g' )
  #p2 = plot( i, cd, '-', marker='None', markersize=1, lw=1, c='k' )
  #p2 = plot( i, cd, '-', marker='.', markersize=1, lw=1, c='k' )
  
  #legend( (p1,p2), ('cl','cd'), 'upper center', shadow=False )
  
  xlabel('dudy')
  ylabel('rms')
  title('Re = ' + k )
  grid(True)
  
  #savefig('plot.png')
  #print('- saved plot.png')

  show()

#----------------------------------------------------
if __name__ == '__main__':
#----------------------------------------------------
  if len(sys.argv) == 1: print('usage: python plot.py data.csv [1]=which_re [undefined]=predicted')
  if len(sys.argv) == 1: exit()

  file = 'undefined'
  if len(sys.argv) > 1: file = str(sys.argv[1])

  which_re = 1
  if len(sys.argv) > 2: which_re = int(sys.argv[2])

  predicted = 'undefined'
  if len(sys.argv) > 3: predicted = str(sys.argv[3])

  main( file, which_re, predicted )
