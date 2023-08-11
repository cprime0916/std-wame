class markt{
    public:
        void shop(bool entered_shop);
        void instruct(bool entered_shop, char items[][1000], int price[], bool can_purchase, bool can_trade, bool can_sell);
        void purchase(int index, int wallet, int price[], char items[][1000], bool can_purchase, bool want_to[]);
        void trade(char items[][1000], char item1[], char item2[], int index1, int index2, int worth_value[], bool can_trade, bool want_to[]);
        void sell(int index, int wallet, int price[], char items[][1000], bool can_purchase, bool want_to[]);
};