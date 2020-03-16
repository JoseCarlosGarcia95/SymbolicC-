#include <gmpxx.h>

#ifndef UTILS_NUMBER_THEORY_INT
#define UTILS_NUMBER_THEORY_INT

#define MAX_MILLERRABIN_IT 8
#define POLLARD_QUICK_ITERATIONS 20
#define TRIAL_DIVISION_MAX 1000000
#define MAX_DIGITS_POLLARD 20

list<mpz_class> factorize_int(mpz_class num);

bool is_int_prime(mpz_class num)
{
    return mpz_probab_prime_p(num.__get_mp(), MAX_MILLERRABIN_IT);
}

list<long> int64_primes_list(long upper_bound)
{
    long m, nsqrt, i, j;
    bool* numbers;
    list<long> prime_list;

    m = upper_bound + 1;
    nsqrt = sqrt(upper_bound);
    prime_list = list<long> {};
    numbers = (bool*)malloc(sizeof(bool) * m);

    for (i = 0; i < nsqrt + 1; i++) {
        numbers[i] = true;
    }

    for (i = 2; i < nsqrt + 1; i++) {
        if (numbers[i]) {
            prime_list.push_back(i);
            for (j = i * i; j < m; j += i) {
                numbers[j] = false;
            }
        }
    }

    free(numbers);

    return prime_list;
}

mpz_class _factorize_trial_division(mpz_class num, list<mpz_class>* factors)
{
    list<long> prime_list;
    prime_list = int64_primes_list(TRIAL_DIVISION_MAX);

    for (long prime : prime_list) {
        while (num % prime == 0) {
            factors->push_back(prime);
            num /= prime;
        }
    }

    return num;
}

mpz_class _pollard_f(mpz_class c, mpz_class n, mpz_class x)
{
    return (x * x + c) % n;
}

mpz_class _pollard_find_factor(mpz_class n, long max_iter)
{
    long i;
    mpz_class y, c, m, r, q, g, x, j, k, ys, minrk;
    gmp_randclass r1(gmp_randinit_default);

    y = r1.get_z_range(n - 2) + 1;
    c = r1.get_z_range(n - 2) + 1;
    m = r1.get_z_range(n - 2) + 1;
    r = q = g = 1;

    i = 0;

    while (g == 1) {
        x = y;
        for (j = 0; j < r; j++) {
            y = _pollard_f(c, n, y);
        }
        k = 0;

        while (k < r && g == 1) {
            ys = y;
            minrk = m;

            if (m > r - k) {
                minrk = r - k;
            }

            for (j = 0; j < minrk; j++) {
                y = _pollard_f(c, n, y);
                q = (q * abs(x - y)) % n;
            }
            g = gcd(q, n);
            k += m;
        }

        r *= 2;

        /*
        if (i >= max_iter) {
            return -1;
        }
*/
        i++;
    }

    if (g == n) {
        while (true) {
            ys = _pollard_f(c, n, ys);
            g = gcd(abs(x - ys), n);
            if (g > 1) {
                break;
            }
        }
    }

    return g;
}

mpz_class _factorize_pollard_quick(mpz_class num, list<mpz_class>* factors)
{
    long i;
    mpz_class factor;
    list<mpz_class> pollard_factors;

    while (true) {
        if (is_int_prime(num)) {
            factors->push_back(num);
            return 1;
        }

        factor = _pollard_find_factor(num, POLLARD_QUICK_ITERATIONS);

        if (factor == -1) {
            return num;
        }

        if (is_int_prime(factor)) {
            num /= factor;
            factors->push_back(factor);
        } else {
            pollard_factors = factorize_int(factor);
            for (mpz_class factor : pollard_factors) {
                factors->push_back(factor);
            }
        }
    }

    return num;
}

// TODO
mpz_class _factorize_siqs(mpz_class num, list<mpz_class>* factors)
{
    u_int64_t digits;
    digits = num.get_str().length();
    return num;
}

list<mpz_class> factorize_int(mpz_class num)
{
    u_int64_t digits;
    list<mpz_class> factors;

    if (num == 1 || is_int_prime(num)) {
        return list<mpz_class> { num };
    }

    factors = list<mpz_class> {};
    num = _factorize_trial_division(num, &factors);

    if (num != 1) {
        digits = num.get_str().length();
        num = _factorize_pollard_quick(num, &factors);
        /*
        if (digits < MAX_DIGITS_POLLARD) {
            num = _factorize_pollard_quick(num, &factors);
        } else {
            num = _factorize_siqs(num, &factors);
        }
        */
    }

    if (num != 1) {
        cerr << "WARNING: We can't find a real factorization for given integer.\n";
        factors.push_back(num);
    }
    return factors;
}

#endif