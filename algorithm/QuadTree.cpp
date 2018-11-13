struct QuadTreeNode {
    int depth; // 结点深度
    int is_leaf; // 是否是叶子结点
    struct Region region; // 区域范围
    struct QuadTreeNode *LU; // 左上子结点指针
    struct QuadTreeNode *LB; // 左下子结点指针
    struct QuadTreeNode *RU; // 右上子结点指针
    struct QuadTreeNode *RB; // 右下子结点指针
    int ele_num; // 位置点数
    struct ElePoint *ele_list[MAX_ELE_NUM]; // 位置点列表
};

void splitNode(struct QuadTreeNode *node) {
    // 获取xy方向上的中间点，用来初始化子结点的范围
    double mid_vertical = (node->region.up + node->region.bottom) / 2;
    double mid_horizontal = (node->region.left + node->region.right) / 2;

    node->is_leaf = 0; // 将是否为叶子结点置为否
    // 填充四个子结点
    node->RU = createChildNode(node, mid_vertical, node->region.up, mid_horizontal, node->region.right);
    node->LU = createChildNode(node, mid_vertical, node->region.up, node->region.left, mid_horizontal);
    node->RB = createChildNode(node, node->region.bottom, mid_vertical, mid_horizontal, node->region.right);
    node->LB = createChildNode(node, node->region.bottom, mid_vertical, node->region.left, mid_horizontal);

    // 遍历结点下的位置点，将其插入到子结点中
    for (int i = 0; i < node->ele_num; i++) {
        insertEle(node, *node->ele_list[i]);
        free(node->ele_list[i]);
        node->ele_num--;
    }
}
