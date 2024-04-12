class LRUCache
{
public:
    // Least Recently Used - 가장 오랫동안 참조되지 않은 페이지를 교체.
    // O(1)만에 값 조회, 수정을 위해 hash_map 사용
    // 어떤 엔티티가 가장 최근에 참조되었는지 순서들을 저장하기 위해서 엔티티들을 Double Linked List 로 연결
    // 헤드쪽으로 갈 수록 가장 최신의 것, 테일쪽으로 갈수록 가장 오래순으로 연결

    struct DLinkedNode
    {
        int key;
        int value;

        DLinkedNode *prev = NULL;
        DLinkedNode *next = NULL;

        DLinkedNode() {}
        DLinkedNode(int k, int v) : key(k), value(v) {}
    };

    int capacity;
    DLinkedNode *head = new DLinkedNode();
    DLinkedNode *tail = new DLinkedNode();

    unordered_map<int, DLinkedNode *> cache;

    LRUCache(int size)
    {

        capacity = size;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {

        if (cache.find(key) == cache.end())
        {
            return -1; // 존재하지 않는 키 값을 검색
        }

        DLinkedNode *current = cache[key]; // 기존에 존재하던 엔티티에 접근

        deleteNode(current);
        addNodeToHead(current);

        return current->value;
    }

    // 현재 엔티티를 DoubleLinkedList에서 제거
    // a - current - b => a - b
    void deleteNode(DLinkedNode *node)
    {

        DLinkedNode *prev_node = node->prev;
        DLinkedNode *next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    // 최신 검색된 노드를 헤드 바로 앞으로 삽입하기
    // 헤드 -  기존 맨 앞 노드  => 헤드 - current - 기존 맨 앞 노드
    void addNodeToHead(DLinkedNode *new_node)
    {

        DLinkedNode *node = head->next;

        new_node->next = node;
        new_node->prev = head;

        head->next = new_node;
        node->prev = new_node;
    }

    void put(int key, int value)
    {

        if (cache.find(key) != cache.end())
        { // 이미 존재한다면
            DLinkedNode *node = cache[key];
            node->value = value; // update
            deleteNode(node);    // DLinkedList 연결 해제
            addNodeToHead(node); // DLinkedList의 앞으로 이동
            return;
        }

        // cout<<"cache.size():"<<cache.size()<<"capacity"<<capacity<<"\n";

        if (cache.size() == capacity)
        { // 이미 사이즈가 풀이라면
            // 가장 오래전에 참조된 엔티티는 tail->prev에 저장되어 있으니 지우기

            int erase_key = tail->prev->key;
            deleteNode(tail->prev); // DLinkedList 연결 해제
            cache.erase(erase_key); // hash map 에서 삭제

            // ! deleteNode 를 통해서 tail->prev 값이 바뀌므로 erase_key 값을 저장하고 사용하여야함
        }

        // 새로운 엔티티 생성 및 해시맵 삽입
        DLinkedNode *new_node = new DLinkedNode(key, value);
        cache[key] = new_node;
        addNodeToHead(new_node); // 링크드 리스트 연결
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */