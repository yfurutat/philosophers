#!/bin/bash

# 1. number_of_philosophers
# 2. time_to_die
# 3. time_to_eat
# 4. time_to_sleep
# 5. number_of_times_each_philosopher_must_eat

ARGV1="200"
ARGV2="800"
ARGV3="100"
ARGV4="3000"
ARGV5="100"
# ARGV3="100@"
# ARGV3="opqij&"

# ARGV1="2147483647"
# ARGV2="2147483647"
# ARGV3="2147483647"
# ARGV4="2147483647"
# ARGV5="2147483647"

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
CMD="./philo $ARGV1 $ARGV2 $ARGV3 $ARGV4 $ARGV5"

echo ${CMD}
$CMD