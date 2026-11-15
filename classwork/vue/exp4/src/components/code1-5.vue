<script setup>
import { reactive, computed } from 'vue';
//定义存放水果信息的数组
// 封装获取图片路径的函数
const getimg = (imgName) => {
  // 这里的路径必须使用相对路径，不能使用 @ 别名
  return new URL(`../assets/images/${imgName}`, import.meta.url).href
}

const fruitlist = reactive([
    { id: 1, fruit: '香橼', pic: getimg('1.jpg'), price: 5, count: 1, state: true },
    { id: 2, fruit: '柚子', pic: getimg('2.jpg'), price: 4.5, count: 1, state: false },
    { id: 3, fruit: '橘子', pic: getimg('3.jpg'), price: 3, count: 1, state: false },
    { id: 4, fruit: '橙子', pic: getimg('4.jpg'), price: 6, count: 1, state: false },
    { id: 5, fruit: '粑粑柑', pic: getimg('5.jpg'), price: 6.5, count: 1, state: false },
    { id: 6, fruit: '柠檬', pic: getimg('6.jpg'), price: 4, count: 1, state: false },
    { id: 7, fruit: '青柠', pic: getimg('7.jpg'), price: 5.2, count: 1, state: false },
])

// 点击了数量 -1 按钮
const onSubClick = (index) => {
    // 数量为1时不能减
    if (fruitlist[index].count > 1) fruitlist[index].count--
}
// 点击了数量 +1 按钮
const onAddClick = (id) => {
    // find() 方法返回数组中满足提供的条件的第一个元素的值。
    const findResult = fruitlist.find(x => x.id === id)
    if (findResult) {
        findResult.count++
    }
}

// 动态计算出勾选水果的总数量
const total = computed(() => {
    let t = 0;
    fruitlist.forEach(x => {
        if (x.state) {
            t += x.count;
        }
    })
    return t;
})
// 已勾选商品的总价格
const amount = computed(() => {
    let a = 0;
    fruitlist.forEach(x => {
        if (x.state)
            a += x.price * x.count;
    })
    return a;
})
// 控制按钮的禁用状态
const isDisabled = computed(() => {
    return total.value === 0    //计算属性是ref数据，计算属性的定义中可以使用其他计算属性
    // 也可以用下面复杂的写法
    // let flag = true
    // fruitlist.forEach(x => {
    //     if (x.state) {
    //         flag = false
    //     }
    // })
    // return flag
})
</script>

<template>
    <div id="box">
        <h1>水果商店—软工2541班王艺杰 </h1>
<table class="table table-bordered table-hover">
            <thead>
                <tr>
                    <th>操作</th>
                    <th>水果名称</th>
                    <th>水果图片</th>
                    <th>单价(斤)</th>
                    <th>数量</th>
                </tr>
            </thead>

            <tbody>
            <tr v-for="(item,index) in fruitlist" :key="item.id">
                <td>
                <input type="checkbox" v-model="item.state" />
                </td>
                <td>{{ item.fruit }}</td>
                <td><img style="width: 50px;height: 50px;border-radius: 50%;" :src="item.pic" alt="" /></td>
                <td>￥{{ item.price }}</td>
                <td>
                <button type="button" @click="onSubClick(index)">-</button>
                <span>{{ item.count }}</span>
                <button type="button" @click="onAddClick(item.id)">+</button>
                </td>
            </tr>
            </tbody>

            <tfoot>
            <tr style="font-weight: bolder;">
                <!-- TODO: 1. 动态计算已勾选的商品的总数量 -->
                <td colspan="2"><span>总数量:{{total}}</span></td>
                <!-- TODO: 2. 动态计算已勾选的商品的总价 -->
                <td colspan="2"><span>总价:{{amount}}元</span></td>
                <!-- TODO: 3. 动态计算按钮的禁用状态 -->
                <td style="text-align: center;">
                <button type="button" class="btn btn-primary" :disabled="isDisabled">结算</button>
                </td>
            </tr>
            </tfoot>


        </table>
    </div>
</template>

<style scoped> 
h1 {
text-align: center;
color: red;
}
</style>