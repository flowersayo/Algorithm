// dfs

let visited; // 티켓을 사용했는지 방문체크 배열
let answer;

let find_answer = false;

function dfs(idx, current, tickets, visit_order)
{

    if (idx == = tickets.length)
    { // 모든 장소를 방문하면
        find_answer = true;
        answer = visit_order;
        return;
    }

    for (let i in tickets)
    {

        if (visited[i] == = true)
        {
            continue;
        }

        let ticket = tickets[i];
        let[origin, dest] = ticket;

        console.log(ticket);

        if (!find_answer &&origin == = current)
        {
            visited[i] = true; // 해당 티켓을 사용했는지
            visit_order.push(dest);
            dfs(idx + 1, dest, tickets, visit_order);

            if (!find_answer)
            {
                visit_order.pop(); // 맨 마지막 요소 지우기
            }
        }

        visited[i] = false;
    }
}

function cmp(a, b)
{

    //  return a[1] > b[1]; // dest 기준 알파벳 오름차순 정렬 Q. 이 코드가 동작하지 않는 이유?

    // 만약에 a 가 더 뒤에 와서 더 크다면 위치를 바꾼다.
    if (a[1] > b[1])
    {
        return 1; // a를 b 뒤로 보낸다
    }
    else if (a[1] < b[1])
    {
        return -1; // a를 b 앞에 둔다
    }
    else
    {
        return 0; // 순서를 바꾸지 않는다
    }
}

function solution(tickets)
{

    visited = new Array(tickets.length).fill(false);

    tickets.sort(cmp);
    dfs(0, "ICN", tickets, ["ICN"]);

    return answer;
}