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
  line = fp.readline() # header
  data = {}
  tol = 1.e-05
  idx = -1
  re0 = 1000.0
  while line:
    line = fp.readline().rstrip('\r\n')
    if not line: break
    s = str.split( line,',' )
    re1 = float(s[0])
    if re1 < re0:
      #print( re1, re0 )
      idx += 1
      data[idx] = {}
      data[idx]['rey'] = []
      data[idx]['dudy'] = []
      data[idx]['tke'] = []
      data[idx]['u'] = []
      data[idx]['v'] = []
      data[idx]['w'] = []
      data[idx]['c'] = []

    re0 = float(s[0])
    data[idx]['rey'].append( float(s[0]) )
    data[idx]['dudy'].append( float(s[2]) )
    data[idx]['tke'].append( float(s[3]) )
    data[idx]['u'].append( float(s[4]) )
    data[idx]['v'].append( float(s[5]) )
    data[idx]['w'].append( float(s[6]) )
    data[idx]['c'].append( float(s[7]) )
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
  print( keys )
  k = keys[which_re]
  print( k )

  if predicted != 'undefined':
    pred = s_read_data_csv( predicted )
    keys = list(pred.keys())
    print( keys )
    p = keys[which_re]
    print( p )
  
  fig = figure()
  ax = subplot(111)

  d1 = ax.loglog( data[k]['dudy'], data[k]['u'], '-', marker='None', markersize=1, lw=1, c='r' )
  d2 = ax.loglog( data[k]['dudy'], data[k]['v'], '-', marker='None', markersize=1, lw=1, c='k' )
  d3 = ax.loglog( data[k]['dudy'], data[k]['w'], '-', marker='None', markersize=1, lw=1, c='b' )
  d4 = ax.loglog( data[k]['dudy'], data[k]['c'], '-', marker='None', markersize=1, lw=1, c='g' )
  if predicted != 'undefined':
    p1 = ax.loglog( pred[p]['dudy'], pred[p]['u'], '-', linestyle='none', marker='o', markersize=1, lw=1, c='r' )
    p2 = ax.loglog( pred[p]['dudy'], pred[p]['v'], '-', linestyle='none', marker='o', markersize=1, lw=1, c='k' )
    p3 = ax.loglog( pred[p]['dudy'], pred[p]['w'], '-', linestyle='none', marker='o', markersize=1, lw=1, c='b' )
    p4 = ax.loglog( pred[p]['dudy'], pred[p]['c'], '-', linestyle='none', marker='o', markersize=1, lw=1, c='g' )
  #p2 = ax.plot( i, cd, '-', marker='None', markersize=1, lw=1, c='k' )
  #p2 = ax.plot( i, cd, '-', marker='.', markersize=1, lw=1, c='k' )
  
  #legend( (d1,d2,d3,d4), ('u','v','w','uv'), 'lower center', shadow=False )
  #ax.legend( (d1,d2,d3,d4), ('u','v','w','uv') )
  
  xlabel('Velocity Gradient du/dy')
  ylabel('Turbulent Stresses')
  title('Dataset = ' + str(k))
  grid(True)
  
  #savefig('plot.png')
  #print('- saved plot.png')

  show()

#----------------------------------------------------
if __name__ == '__main__':
#----------------------------------------------------
  if len(sys.argv) == 1: print('usage: python plot.py data.csv [which_re]=1 [predicted]=undefined')
  if len(sys.argv) == 1: exit()

  file = 'undefined'
  if len(sys.argv) > 1: file = str(sys.argv[1])

  which_re = 1
  if len(sys.argv) > 2: which_re = int(sys.argv[2])

  predicted = 'undefined'
  if len(sys.argv) > 3: predicted = str(sys.argv[3])

  main( file, which_re, predicted )
