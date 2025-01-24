#!/bin/bash
#SBATCH --job-name=vaddOpenMP
#SBATCH --account=COMS033964
#SBATCH --nodes=1
#SBATCH --time=00:10:00
#SBATCH --exclusive
#SBATCH --partition=teach_cpu
#SBATCH --cpus-per-task=1

export OMP_NUM_THREADS=8
              
./vadd                   