# push_swap

python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l && ./push_swap $ARG | ./checker_Mac $ARG