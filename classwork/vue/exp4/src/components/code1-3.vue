<script setup>
import { reactive,ref } from 'vue'

const list = reactive([
    {province: "河南省", city: "郑州市", spot: "少林寺" },
    {province: "河南省", city: "洛阳市", spot: "龙门石窟" },
    {province: "湖北省", city: "长沙市", spot: "橘子洲头" },
    {province: "湖南省", city: "武汉市", spot: "黄鹤楼" },
])
//输入代码
const city = ref("")
const province = ref("")
const spot = ref("")

const add = () => {
    if (!province.value || !city.value || !spot.value)
        alert("输入框不能为空!");
    else {
        if (list.some(item => item.spot == spot.value))
            alert("景点已存在!");
        else
            list.push({ province: province.value, city: city.value, spot: spot.value });
    }
    province.value = "";
    city.value = "";
    spot.value = "";
}
const del = (n) => {
    list.splice(n, 1);
}
</script>

<template>
<h1>软工2541班王艺杰</h1>
<div>
    <div>省份：<input type="text" v-model="province"></div>
    <div>城市：<input type="text" v-model="city"></div>
    <div>景点：<input type="text" v-model="spot"></div>
</div>
    <button class="btn" @click="add">添加景点</button>
<table>
    <tr>
        <th>序号</th>
        <th>省份</th>
        <th>城市</th>
        <th>景点</th>
        <th>操作</th>
    </tr>
    <tr v-for="(item, index) in list" :key ="item">
        <td>{{ index + 1 }}</td>
        <td>{{ item.province }}</td>
        <td>{{ item.city }}</td>
        <td>{{ item.spot }}</td>
        <td><button @click="del(index)">删除</button></td>
    </tr>
    
</table>
</template>

<style scoped>
h1{text-align:center;}
button.btn {
    margin-bottom: 20px;
}

table {
    border: 3px solid red;
    border-collapse: collapse;
}

td,
th {
    border: 1px solid red;
}
</style>