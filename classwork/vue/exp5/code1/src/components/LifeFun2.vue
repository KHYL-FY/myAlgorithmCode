
<script setup>
import { ref, onMounted } from 'vue'
const list = ref([])
onMounted(() => {  //生命周期函数onMounted,经常在该函数中获取组件所需要的数据
  fetch('https://applet-base-api-t.itheima.net/api/goods') //利用fetch异步获取数据
    .then(res => res.json())
    .then(res => {
      console.log(res)
      list.value = res.data //将获取的数据转换成响应式数据
    })
})
</script>

<template>
  <h1>软工2541班王艺杰</h1>
  <table>
    <caption>商品列表展示</caption>
    <tr>
      <th>商品id</th>
      <th>商品名称</th>
      <th>商品价格</th>
      <th>商品特点</th>
    </tr>
    <tbody>
      <tr v-for="item in list" :key="item.id">
        <td>{{ item.id }}</td>
        <td>{{ item.goods_name }}</td>
        <td>{{ item.goods_price }}</td>
        <td>{{ item.tags }}</td>
      </tr>
    </tbody>
  </table>
</template>

<style scoped>
h1 {
  text-align: center;
  color: red;
}

table {
  width: 900px;
  margin: 0 auto;
  border-collapse: collapse;
  background-color: azure;
}

caption {
  font-size: 20px;
  color: blue;
  font-weight: bold;
}

th,
td {
  border: 1px solid #000;
  height: 30px;
}

tbody>tr:hover{
  background-color: pink;
}
</style>