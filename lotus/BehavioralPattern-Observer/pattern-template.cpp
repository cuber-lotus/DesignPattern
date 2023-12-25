#include <list>
#include <string>

using std::string;
template <typename T>
using List = std::list<T>;

/**
 * @brief
 * 接受通知对象的操作函数的需要继承的类
 */
class IProgress {
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress()                 = default;
};

class FileSplitter {
    string m_filePath;
    int    m_fileNumber;

    // *****************************
    // 核心 存储需要通知的对象
    // 对应上面的通知基类
    // *****************************
    List<IProgress*> m_iprogressList;  // 抽象通知机制，支持多个观察者

public:
    FileSplitter(const string& filePath, int fileNumber)
        : m_filePath(filePath), m_fileNumber(fileNumber) {
    }

    void addIProgress(IProgress* iprogress) {
        m_iprogressList.push_back(iprogress);
    }

    void removeIProgress(IProgress* iprogress) {
        m_iprogressList.remove(iprogress);
    }

public:
    /**
     * @brief
     * 具体的事件
     */
    void split() {
        // 1.读取大文件

        // 2.分批次向小文件中写入
        for (int i = 0; i < m_fileNumber; i++) {
            //...

            float progressValue = m_fileNumber;
            progressValue       = (i + 1) / progressValue;

            // 发送一次通知
            onProgress(progressValue);
        }
    }

protected:
    /**
     * @brief
     * 处理所有对象的通知信息
     * @param value
     */
    virtual void onProgress(float value) {
        List<IProgress*>::iterator itor = m_iprogressList.begin();

        while (itor != m_iprogressList.end()) {
            (*itor)->DoProgress(value);  // 更新进度条
            itor++;
        }
    }
};