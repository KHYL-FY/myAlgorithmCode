<script setup>
import { reactive, ref, watch, computed } from 'vue';
const allstate=ref(false)    //该数据与“全选/全不选”复选框进行v-model绑定
const list = reactive([
  { id: 1, name: "iPhone 7", price: 6188, count: 1, state:false },
  { id: 2, name: "iPad Pro", price: 5888, count: 1, state:false},
  { id: 3, name: "MaxBook Pro", price: 21488, count: 1, state:false},
  { id: 4, name: "SAMSUNG GalaxyS22", price: 3649, count: 1, state:false},
  { id: 5, name: "HUAWEI P60", price: 4488, count: 1, state:false}
])
//单击“-”按钮
const sub = (id) => {
  const findResult = list.find(function (x) {
    return x.id === id;
  });
  if (findResult && findResult.count > 1) {
    findResult.count--;
  }
}
//单击“+”按钮
const add = (id) => {
  const findResult = list.find(function (x) {
    return x.id === id;
  });
  if (findResult) {
    findResult.count++;
  }
}
//单击“移除”按钮
const del = (id) => {
  list.some((x, index) => {
    if (x.id == id) {
      list.splice(index, 1);
    }
    return;
  });
}
//“全选/全不选”复选框控制下面复选框
const allChange = () => {
  if (allstate.value == true) {
    list.forEach((item) => {
      item.state = true;
    })
  } else {
    list.forEach((item) => {
      item.state = false;
    });
  }
}
//方法一： 利用watch监听完成下面按钮对上面按钮的控制
watch(list,()=>{
  let flag=true
  list.forEach(item=>{
    if(!item.state)   flag=false
  })
  allstate.value=flag
})
//利用计算属性计算总价
const totalPrice = computed(() => {
  var t = 0;
  list.forEach((item) => {
    if (item.state) t += item.price * item.count;
  });
  return t;
});
</script>

<template>
  <h1>商品列表展示-软工2541王艺杰</h1>
  <table>
    <thead>
      <tr>
        <th>序号</th>
        <th>商品名称</th>
        <th>商品单价</th>
        <th>购买数量</th>
        <th>操作</th>
        <th>
          <input type="checkbox" id="checkBoxAll" v-model="allstate" @change="allChange" />全选/全不选
        </th>
      </tr>
    </thead>
    <tbody>
      <tr v-for="(item, index) in list" :key="item.id">
        <td>{{ index + 1 }}</td>
        <td>{{ item.name }}</td>
        <td>{{ item.price }}</td>
        <td>
          <button class="btn" @click="sub(item.id)">-</button>
          {{ item.count }}
          <button class="btn" @click="add(item.id)">+</button>
        </td>
        <td>
          <button class="btns" @click="del(item.id)">移除</button>
        </td>
        <td>
          <input type="checkbox" name="list" v-model="item.state"/>
        </td>
      </tr>
    </tbody>
    <tfoot>
      <tr>
        <td colspan="6">总价：￥{{ totalPrice }}</td>
      </tr>
    </tfoot>
  </table>
</template>

<style scoped>
h1{text-align: center;}
table {
  border: 1px solid #e9e9e9e9;
  border-collapse: collapse;
  border-spacing: 0;
  margin: 0 auto;
}

th,
td {
  padding: 8px 16px;
  border: 1px solid #e9e9e9e9;
}

th {
  background: #f7f7f7;
  color: #5c6c77;
  font-weight: 600;
  white-space: nowrap;
}

.btn {
  width: 20px;
  height: 20px;
  border-radius: 50%;
  border: 1px solid #cccccc;
  background: #ffffff;
  color: #778899;
}

.btns {
  width: 50px;
  height: 20px;
  border-radius: 5px;
  border: 1px solid #cccccc;
  background: #ffffff;
  color: #778899;
  line-height: 20px;
}
</style>
