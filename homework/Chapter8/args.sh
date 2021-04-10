###1
python mlfq.py -n 2 -j 2 -M 0 -q 5 -m 20
### 2
## try 1
# case 1
python mlfq.py -n 3 -j 1 -l 0,200,0 -q 10 -c
# case 2
python mlfq.py -n 3 -q 10 -j 2 -l 0,200,0:100,20,0 -c
# case 3
python mlfq.py -n 3 -q 10 -j 2 -l 0,200,0:100,20,1 -S -c
# case 4
## try 2
# case 1
python mlfq.py -n 3 -q 10 -j 2 -l 0,100,0:100,50,5 -S -c
# case 2
python mlfq.py -n 3 -q 10 -j 2 -l 0,140,0:100,50,5 -B 50 -S -c
### 3
python mlfq.py -n 1 -q 10 -j 5 -M 0 -m 100 -c
### 4
python mlfq.py -S -n 3 -q 10 -j 2 -l 0,99,1:0,100,0 -i 0 -c