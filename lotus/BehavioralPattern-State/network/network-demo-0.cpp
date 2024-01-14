enum NetworkState {
    Network_Open,
    Network_Close,
    Network_Connect,
};

class NetworkProcessor {
    NetworkState state;

public:
    void Operation() {
        if (state == Network_Open) {
            //**********
            state = Network_Close;
        } else if (state == Network_Close) {
            //..........
            state = Network_Connect;
        } else if (state == Network_Connect) {
            //$$$$$$$$$$
            state = Network_Open;
        }
    }
};
