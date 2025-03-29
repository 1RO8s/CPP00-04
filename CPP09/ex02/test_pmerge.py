#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import subprocess
import random
import sys
import os
import time

# termcolorモジュールをオプションでインポート
try:
    from termcolor import colored
    HAS_TERMCOLOR = True
except ImportError:
    HAS_TERMCOLOR = False

def print_colored(text, color):
    """色付きのテキストを出力（termcolorがない場合はフォールバック）"""
    if HAS_TERMCOLOR:
        print(colored(text, color))
    else:
        print(text)

def main():
    """メイン関数"""
    # ヘッダー表示
    print_colored("PmergeMe テスト - Pythonバージョン", "blue")
    print("========================================")

    # 引数の処理
    if len(sys.argv) > 1:
        try:
            num_elements = int(sys.argv[1])
            print_colored(f"要素数: {num_elements}", "yellow")
        except ValueError:
            print("エラー: 要素数は整数で指定してください")
            sys.exit(1)
    else:
        num_elements = 3000
        print_colored(f"要素数: {num_elements} (デフォルト)", "yellow")

    # PmergeMeの存在確認
    if not os.path.isfile("./PmergeMe"):
        print("エラー: PmergeMeプログラムが見つかりません。コンパイルしてください。")
        sys.exit(1)

    # ランダム数列の生成
    print_colored("ランダム数列を生成中...", "green")
    random_numbers = [random.randint(1, 10000) for _ in range(num_elements)]
    
    # 最初の10個だけ表示
    preview = " ".join(map(str, random_numbers[:10]))
    print_colored(f"生成された数列の一部: {preview}...", "yellow")

    # PmergeMeの実行
    print_colored("PmergeMeを実行中...", "green")
    print("----------------------------------------")

    # 時間計測とPmergeMeの実行
    start_time = time.time()
    try:
        result = subprocess.run(
            ["./PmergeMe"] + list(map(str, random_numbers)),
            capture_output=True,
            text=True,
            check=True
        )
        end_time = time.time()
        
        # 出力の表示
        print(result.stdout)
        
        # 計測時間の表示（pythonからの計測も表示）
        elapsed_time = (end_time - start_time) * 1000000  # マイクロ秒に変換
        print(f"Python側で計測した実行時間: {elapsed_time:.2f} us")
        
    except subprocess.CalledProcessError as e:
        print(f"エラー: PmergeMeの実行に失敗しました")
        print(f"エラー出力: {e.stderr}")
        sys.exit(1)

    print("----------------------------------------")
    print_colored("テスト完了", "blue")

    # ソートの検証（オプション）
    verify_sorting(result.stdout, random_numbers)

def verify_sorting(output, original_numbers):
    """ソート結果が正しいか検証する"""
    # 'Before:' と 'After:' の行を探す
    lines = output.split('\n')
    before_line = None
    after_line = None
    
    for line in lines:
        if line.startswith("Before:"):
            before_line = line
        elif line.startswith("After:"):
            after_line = line
    
    if not after_line:
        print("ソート結果の検証: 出力から 'After:' の行が見つかりませんでした")
        return
        
    # 数値のみを抽出
    sorted_numbers_str = after_line.replace("After:", "").strip()
    
    # スペースで分割して整数に変換（複数行に渡る場合も考慮）
    sorted_numbers = []
    for num_str in sorted_numbers_str.split():
        try:
            sorted_numbers.append(int(num_str))
        except ValueError:
            # 数値に変換できない場合はスキップ
            continue
    
    # Pythonでソートした結果と比較
    expected_sorted = sorted(original_numbers)
    
    # 要素数が合わない場合は警告を表示して処理続行
    if len(sorted_numbers) != len(expected_sorted):
        print(f"警告: ソート結果の要素数が一致しません: {len(sorted_numbers)} vs {len(expected_sorted)}")
        print("要素数の不一致のため、可能な範囲で検証を続行します")
    
    # 最小の長さを使用して比較
    min_length = min(len(sorted_numbers), len(expected_sorted))
    mismatch_count = 0
    
    for i in range(min_length):
        if sorted_numbers[i] != expected_sorted[i]:
            mismatch_count += 1
    
    if mismatch_count == 0:
        print_colored("✅ ソート結果の検証: 正確にソートされています", "green")
    else:
        error_percentage = (mismatch_count / min_length) * 100
        print_colored(f"❌ ソート結果の検証: {mismatch_count}個の不一致があります ({error_percentage:.2f}%)", "red")
        
        # 最初の5つの不一致を表示
        shown = 0
        for i in range(min_length):
            if sorted_numbers[i] != expected_sorted[i]:
                print(f"位置 {i}: {sorted_numbers[i]} (実際) vs {expected_sorted[i]} (期待)")
                shown += 1
                if shown >= 5:
                    print("...")
                    break

if __name__ == "__main__":
    main() 