#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void log_to_file(const char *filename, const char *msg) {
    FILE *f = fopen(filename, "a");
    if (f) {
        time_t now = time(NULL);
        fprintf(f, "[%s] %s\n", strtok(ctime(&now), "\n"), msg);
        fclose(f);
    }
}

// Обробник для таймера 1
void handler1(int sig, siginfo_t *si, void *uc) {
    log_to_file("log1.txt", "Timer 1 fired");
}

// Обробник для таймера 2
void handler2(int sig, siginfo_t *si, void *uc) {
    log_to_file("log2.txt", "Timer 2 fired");
}

timer_t create_timer(int signo, void (*handler)(int, siginfo_t *, void *), int interval_sec) {
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(signo, &sa, NULL);

    struct sigevent sev = {0};
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = signo;

    timer_t timerid;
    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        perror("timer_create");
        exit(1);
    }

    struct itimerspec its = {
        .it_value.tv_sec = interval_sec,
        .it_interval.tv_sec = interval_sec
    };

    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        perror("timer_settime");
        exit(1);
    }

    return timerid;
}

int main() {
    // Створюємо два таймери з різними сигналами
    create_timer(SIGRTMIN,     handler1, 2);  // кожні 2 сек
    create_timer(SIGRTMIN + 1, handler2, 5);  // кожні 5 сек

    // Нескінченний цикл очікування
    while (1) pause();

    return 0;
}

