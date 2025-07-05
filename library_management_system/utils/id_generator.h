class IDGeneratorUtil {
    static unsigned int id;
 public:
    static unsigned int getNewID();
    static bool isValidID(unsigned int checkId);
};