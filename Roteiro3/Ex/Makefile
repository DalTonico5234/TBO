all:

debug_compile_0:
	gcc *.c -c -g -Wall -Wextra -Werror

compile_0:
	gcc *.c -c

compile_bubble:
	gcc	main.o bubble_sort.o -o main

compile_insertion:
	gcc	main.o insertion_sort.o -o main

compile_selection:
	gcc main.o selection_sort.o -o main

compile_shaker:
	gcc	main.o shaker_sort.o -o main

clear:
	rm *.o

run: run_nearly_sorted_1K run_nearly_sorted_10K run_nearly_sorted_100K run_reverse_sorted_1K run_reverse_sorted_10K run_reverse_sorted_100K run_sorted_1K run_sorted_10K run_sorted_100K run_unif_rand_1K run_unif_rand_10K run_unif_rand_100K

debug: debug_nearly_sorted_1K debug_nearly_sorted_10K debug_nearly_sorted_100K debug_reverse_sorted_1K debug_reverse_sorted_10K debug debug_reverse_sorted_100K debug_sorted_1K debug_sorted_10K debug_sorted_100K debug_unif_rand_1K debug_unif_rand_10K debug_unif_rand_100K

run_nearly_sorted_1K:
	./main 1000 <in/nearly_sorted/1Knearly_sorted.txt >>out.txt

run_nearly_sorted_10K:
	./main 10000 <in/nearly_sorted/10Knearly_sorted.txt >>out.txt

run_nearly_sorted_100K:
	./main 100000 <in/nearly_sorted/100Knearly_sorted.txt >>out.txt

run_reverse_sorted_1K:
	./main 1000 <in/reverse_sorted/1Kreverse_sorted.txt >>out.txt

run_reverse_sorted_10K:
	./main 10000 <in/reverse_sorted/10Kreverse_sorted.txt >>out.txt

run_reverse_sorted_100K:
	./main 100000 <in/reverse_sorted/100Kreverse_sorted.txt >>out.txt

run_sorted_1K:
	./main 1000 <in/sorted/1Ksorted.txt >>out.txt

run_sorted_10K:
	./main 10000 <in/sorted/10Ksorted.txt >>out.txt

run_sorted_100K:
	./main 100000 <in/sorted/100Ksorted.txt >>out.txt

run_unif_rand_1K:
	./main 1000 <in/unif_rand/1Kunif_rand.txt >>out.txt

run_unif_rand_10K:
	./main 10000 <in/unif_rand/10Kunif_rand.txt >>out.txt

run_unif_rand_100K:
	./main 100000 <in/unif_rand/100Kunif_rand.txt >>out.txt

debug_nearly_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/nearly_sorted/1Knearly_sorted.txt >>out.txt

debug_nearly_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/nearly_sorted/10Knearly_sorted.txt >>out.txt

debug_nearly_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/nearly_sorted/100Knearly_sorted.txt >>out.txt

debug_reverse_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/reverse_sorted/1Kreverse_sorted.txt >>out.txt

debug_reverse_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/reverse_sorted/10Kreverse_sorted.txt >>out.txt

debug_reverse_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/reverse_sorted/100Kreverse_sorted.txt >>out.txt

debug_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/sorted/1Ksorted.txt >>out.txt

debug_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/sorted/10Ksorted.txt >>out.txt

debug_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/sorted/100Ksorted.txt >>out.txt

debug_unif_rand_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/unif_rand/1Kunif_rand.txt >>out.txt

debug_unif_rand_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/unif_rand/10Kunif_rand.txt >>out.txt

debug_unif_rand_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/unif_rand/100Kunif_rand.txt >>out.txt

debug_nearly_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/nearly_sorted/1Knearly_sorted.txt >>out.txt

debug_nearly_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/nearly_sorted/10Knearly_sorted.txt >>out.txt

debug_nearly_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/nearly_sorted/100Knearly_sorted.txt >>out.txt

debug_reverse_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/reverse_sorted/1Kreverse_sorted.txt >>out.txt

debug_reverse_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/reverse_sorted/10Kreverse_sorted.txt >>out.txt

debug_reverse_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/reverse_sorted/100Kreverse_sorted.txt >>out.txt

debug_sorted_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/sorted/1Ksorted.txt >>out.txt

debug_sorted_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/sorted/10Ksorted.txt >>out.txt

debug_sorted_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/sorted/100Ksorted.txt >>out.txt

debug_unif_rand_1K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 1000 <in/unif_rand/1Kunif_rand.txt >>out.txt

debug_unif_rand_10K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10000 <in/unif_rand/10Kunif_rand.txt >>out.txt

debug_unif_rand_100K:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 100000 <in/unif_rand/100Kunif_rand.txt >>out.txt