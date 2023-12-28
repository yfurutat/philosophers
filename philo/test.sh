#!/bin/bash

# 1. number_of_philosophers
# 2. time_to_die
# 3. time_to_eat
# 4. time_to_sleep
# 5. number_of_times_each_philosopher_must_eat

N_PHILOS="200"
T_DIE="800"
T_EAT="200"
T_SLEEP="200"
MIN_T_EAT="7"
# T_EAT="100@"
# T_EAT="opqij&"

# N_PHILOS="2147483647"
# T_DIE="2147483647"
# T_EAT="2147483647"
# T_SLEEP="2147483647"
# MIN_T_EAT="2147483647"

# ARGS1="./philo \
# 2147483647 \
# 21479p83647 \
# 2147483647 \
# 2147483647 \
# tur&"

# ARGS2="./philo \
# 200 \
# 800 \
# 100 \
# 100 \
# 3000"

# echo ${ARGS1}
# $ARGS1
CMD="./philo $N_PHILOS $T_DIE $T_EAT $T_SLEEP $MIN_T_EAT"

echo ${CMD}
$CMD