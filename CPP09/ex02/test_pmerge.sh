#!/bin/bash

# 色のエスケープシーケンス
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}PmergeMe テスト - 3000個のランダム数列${NC}"
echo "========================================"

# 引数のチェック
if [ $# -eq 1 ]; then
    NUM_ELEMENTS=$1
    echo -e "${YELLOW}要素数: $NUM_ELEMENTS${NC}"
else
    NUM_ELEMENTS=3000
    echo -e "${YELLOW}要素数: $NUM_ELEMENTS (デフォルト)${NC}"
fi

# PmergeMeが存在するか確認
if [ ! -f "./PmergeMe" ]; then
    echo "エラー: PmergeMeプログラムが見つかりません。コンパイルしてください。"
    exit 1
fi

# 数列の生成（macOS対応）
echo -e "${GREEN}ランダム数列を生成中...${NC}"
RANDOM_NUMBERS=$(jot -r $NUM_ELEMENTS 1 10000 | tr '\n' ' ')

# 最初の10個だけ表示
PREVIEW=$(echo $RANDOM_NUMBERS | cut -d' ' -f1-10)
echo -e "${YELLOW}生成された数列の一部: ${PREVIEW}...${NC}"

echo -e "${GREEN}PmergeMeを実行中...${NC}"
echo "----------------------------------------"

# 時間計測とPmergeMeの実行
time ./PmergeMe $RANDOM_NUMBERS

echo "----------------------------------------"
echo -e "${BLUE}テスト完了${NC}" 