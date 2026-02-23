soma=0

for ((i = 0; i < 10; i++)); do
    ARG=($(shuf -i 1-2500 -n 100))

    output=$(./a.out "${ARG[@]}")
    
    echo "$output" | ./checker_linux "${ARG[@]}"
    
    nb=$(echo "$output" | wc -l)
    soma=$((soma + nb))
    
    valgrind --leak-check=full ./push_swap "${ARG[@]}" 2>&1 | grep "total heap usage"

    printf "Iteração %d: %d linhas\n" "$i" "$nb"
    echo "-----------------------------------"
done

media=$((soma / 10))
printf "\nA média é: %d\n" "$media"