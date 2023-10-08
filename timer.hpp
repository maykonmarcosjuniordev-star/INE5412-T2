class Timer {
public:
    Timer();
    void start() {
        time = 0;
        running = true;
    }
    void stop() {
        running = false;
    }
    int get_time()  {
        return time;
    }
    void set_time(int t) {
        time = t;
    }
    void pass_time() {
        time++;
    }
    int time = 0;
    bool running = false;
};