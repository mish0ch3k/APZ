#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sqlite3.h>
#include <time.h>

#define DB_NAME "crash_log.db"

void log_to_db(int pid, int ppid, int signum) {
    sqlite3 *db;
    sqlite3_open(DB_NAME, &db);

    char *err = 0;
    const char *create_sql =
        "CREATE TABLE IF NOT EXISTS Crashes ("
        "id INTEGER PRIMARY KEY, "
        "timestamp TEXT, pid INT, ppid INT, signal TEXT);";
    sqlite3_exec(db, create_sql, 0, 0, &err);

    time_t now = time(NULL);
    char timestr[64];
    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", localtime(&now));

    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO Crashes (timestamp, pid, ppid, signal) "
             "VALUES ('%s', %d, %d, '%s');",
             timestr, pid, ppid,
             (signum == SIGSEGV ? "SIGSEGV" :
              signum == SIGFPE  ? "SIGFPE"  :
              signum == SIGILL  ? "SIGILL"  : "UNKNOWN"));

    sqlite3_exec(db, query, 0, 0, &err);
    sqlite3_close(db);
}

int main() {
    pid_t child = fork();

    if (child == 0) {
        execl("./test", "./test", NULL);
        exit(1); // Якщо не вдалося виконати test
    }

    int status;
    waitpid(child, &status, 0);

    if (WIFSIGNALED(status)) {
        int sig = WTERMSIG(status);
        log_to_db(child, getpid(), sig);
        printf("Аварійне завершення: сигнал %d\n", sig);
    } else {
        printf("test завершився нормально\n");
    }

    return 0;
}

