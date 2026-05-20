all: compile_0 compile_v8 clear run

debug: debug_compile_0 compile_v8 clear quick_debug

debug_compile_0:
	gcc *.c -c -g -Wall -Wextra -Werror

compile_0:
	gcc *.c -c

compile_v1:
	gcc main.o quick_v1.o -o main

compile_v2:
	gcc main.o quick_v2.o insertion_sort.o -o main

compile_v3:
	gcc main.o quick_v3.o -o main

compile_v4:
	gcc main.o quick_v4.o insertion_sort.o -o main

compile_v5:
	gcc main.o quick_v5.o stack.o -lm -o main

compile_v6:
	gcc main.o quick_v6.o stack.o insertion_sort.o -lm -o main

compile_v7:
	gcc main.o quick_v7.o insertion_sort.o stack.o -o main

compile_v8:
	gcc main.o quick_v8.o insertion_sort.o -o main

clear:
	rm *.o

clear_output:
	true > out.txt
	true > test.txt
	true > time.txt

real_run: run_nearly_sorted_100000 \
run_nearly_sorted_1000000 \
run_nearly_sorted_10000000 \
run_reverse_sorted_100000 \
run_reverse_sorted_1000000 \
run_reverse_sorted_10000000 \
run_sorted_100000 \
run_sorted_1000000 \
run_sorted_10000000 \
run_unif_rand_100000 \
run_unif_rand_1000000 \
run_unif_rand_10000000 \
run_few_uniq_10M_unif_rand \
run_few_uniq_10M_sorted \

simplified_run: run_nearly_sorted_100000 \
run_reverse_sorted_100000 \
run_sorted_100000 \
run_unif_rand_100000 \
run_unif_rand_1000000 \
run_unif_rand_1000000 \
run_few_uniq_10M_unif_rand \
run_few_uniq_10M_sorted \

run: clear_output real_run

# debug: debug_nearly_sorted_100000 debug_nearly_sorted_1000000 debug_reverse_sorted_100000 debug_reverse_sorted_1000000 debug_sorted_100000 debug_sorted_1000000 debug_unif_rand_100000 debug_unif_rand_1000000

quick_debug:
	valgrind --leak-check=full --show-leak-kinds=all -s ./main 1000 <../../Roteiro3/Ex/in/unif_rand/1Kunif_rand.txt >test.txt

run_few_uniq_10M_sorted:
	./main 10000000 <in/few_uniq/10M_const_keys_sorted.txt >out.txt

run_few_uniq_10M_unif_rand:
	./main 10000000 <in/few_uniq/10M_const_keys_unif_rand.txt >out.txt

run_nearly_sorted_100000:
	./main 100000 <in/nearly_sorted/100000.txt >out.txt

run_nearly_sorted_1000000:
	./main 1000000 <in/nearly_sorted/1000000.txt >out.txt

run_nearly_sorted_10000000:
	./main 10000000 <in/nearly_sorted/10000000.txt >out.txt

run_reverse_sorted_100000:
	./main 100000 <in/reverse_sorted/100000.txt >out.txt

run_reverse_sorted_1000000:
	./main 1000000 <in/reverse_sorted/1000000.txt >out.txt

run_reverse_sorted_10000000:
	./main 10000000 <in/reverse_sorted/10000000.txt >out.txt

run_sorted_100000:
	./main 100000 <in/sorted/100000.txt >out.txt

run_sorted_1000000:
	./main 1000000 <in/sorted/1000000.txt >out.txt

run_sorted_10000000:
	./main 10000000 <in/sorted/10000000.txt >out.txt

run_unif_rand_100000:
	./main 100000 <in/unif_rand/100000.txt >out.txt

run_unif_rand_1000000:
	./main 1000000 <in/unif_rand/1000000.txt >out.txt

run_unif_rand_10000000:
	./main 10000000 <in/unif_rand/10000000.txt >out.txt

debug_nearly_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/nearly_sorted/100000.txt >out.txt

debug_nearly_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/nearly_sorted/1000000.txt >out.txt

debug_reverse_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/reverse_sorted/100000.txt >out.txt

debug_reverse_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/reverse_sorted/1000000.txt >out.txt

debug_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/sorted/100000.txt >out.txt

debug_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/sorted/1000000.txt >out.txt

debug_unif_rand_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/unif_rand/100000.txt >out.txt

debug_unif_rand_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/unif_rand/1000000.txt >out.txt

debug_nearly_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/nearly_sorted/100000.txt >out.txt

debug_nearly_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/nearly_sorted/1000000.txt >out.txt

debug_reverse_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/reverse_sorted/100000.txt >out.txt

debug_reverse_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/reverse_sorted/1000000.txt >out.txt

debug_sorted_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/sorted/100000.txt >out.txt

debug_sorted_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/sorted/1000000.txt >out.txt

debug_unif_rand_100000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/unif_rand/100000.txt >out.txt

debug_unif_rand_1000000:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000000 <in/unif_rand/1000000.txt >out.txt
